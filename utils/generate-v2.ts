// This is a simple script that will convert the v3 Watchy YAML to v2 settings
// for backwars compatibility with other (older) hardware.

import * as fs from "fs";

import yaml, { YAMLMap, YAMLSeq } from "yaml";

export default () => {
  const v3 = fs.readFileSync("../watchy-v3.yaml", "utf8");

  const v2 = yaml.parseDocument(
    v3
      .replace("pins-v3.yaml", "pins-v2.yaml")
      .replace("miso_pin: $SPI_MISO_PIN", "")
      .replaceAll("# - pcf8563.read_time:", "- pcf8563.read_time:")
      .replaceAll("# - pcf8563.write_time:", "- pcf8563.write_time:"),
    { uniqueKeys: false }
  );

  v2.set("esp32", {
    board: "esp32dev",
    partitions: "min_spiffs.csv",
  });

  v2.addIn(["time"], {
    platform: "pcf8563",
    id: "pcf",
    update_interval: "never",
    address: "0x51",
  });

  const binarySensor = v2.get("binary_sensor");

  if (binarySensor instanceof YAMLSeq) {
    const isCharging = binarySensor.items.find(
      (x) =>
        x instanceof YAMLMap &&
        x.items.find((pair) => pair.key.value == "id" && pair.value.value == "is_charging")
    );
    if (isCharging instanceof YAMLMap) {
      isCharging.delete("pin");
      isCharging.set("platform", "template");
    }
  }

  fs.writeFileSync("../watchy-v2.yaml", v2.toString());
};
