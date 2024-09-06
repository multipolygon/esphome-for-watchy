import yaml, { YAMLMap, Scalar } from "yaml";
import * as fs from "fs";

export default () => {
  const config = yaml.parseDocument(fs.readFileSync("../config.yaml", "utf8"));
  const example = yaml.parseDocument(
    fs.readFileSync("../config-example.yaml", "utf8")
  );
  if (
    config.contents instanceof YAMLMap &&
    example.contents instanceof YAMLMap
  ) {
    config.contents.items.forEach((i) => {
      if (i.key instanceof Scalar && i.value instanceof Scalar) {
        // TODO
        // console.log(i.key.value, i.value.value);
      }
    });
  }
};
