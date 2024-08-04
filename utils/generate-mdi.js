import * as fs from "fs";

export default () => {
  const required = fs
    .readFileSync("../watchy.yaml")
    .toString()
    .match(/"\$mdi\w+?"/g)
    .map((x) => x.replaceAll('"', "").replaceAll("$", ""));

  console.log(required.length, "icons required");

  function camelize(str) {
    return str
      .replace(/(?:^\w|[A-Z]|\b\w)/g, function (word, index) {
        return index === 0 ? word.toLowerCase() : word.toUpperCase();
      })
      .replace(/\s+/g, "");
  }

  const x = fs
    .readFileSync("../fonts/mdi/scss/_variables.scss")
    .toString()
    .split("(")[1]
    .split(")")[0]
    .trim()
    .split("\n")
    .map((l) => l.trim().replaceAll('"', "").replaceAll(",", "").replaceAll("-", " ").split(": "))
    .map(([name, code]) => [camelize("mdi " + name), code])
    .filter(([name, code]) => required.includes(name));

  console.log(x.length);

  fs.writeFileSync(
    "../mdi.yaml",
    x.map(([name, code]) => `${name}: "\\U000${code}"`).join("\n") + "\n"
  );
  fs.writeFileSync(
    "../mdi.h",
    x.map(([name, code]) => `const char *${name} = "\\U000${code}";`).join("\n") + "\n"
  );
};
