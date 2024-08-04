// This is a simple script that will convert the v3 Watchy YAML to v2 settings
// for backwars compatibility with other (older) hardware.

import yaml from "yaml";
import * as fs from "fs";

export default () => {
  const v3 = fs.readFileSync("../watchy.yaml", "utf8");

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

  v2.get("time").add({
    platform: "pcf8563",
    id: "pcf",
    update_interval: "never",
    address: "0x51",
  });

  const isCharging = v2
    .get("binary_sensor")
    .items.find((x) =>
      x.items.find((pair) => pair.key.value == "id" && pair.value.value == "is_charging")
    );
  isCharging.delete("pin");
  isCharging.set("platform", "template");

  fs.writeFileSync("../v2-watchy.yaml", v2.toString());
};
