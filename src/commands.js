const { exec } = require("child_process");

const help = require("./commands/help.js");
const compare = require("./commands/compare.js");
const pay = require("./commands/pay.js");
const evaluate = require("./commands/evaluate.js");

const commands = { help, compare, pay, evaluate };

module.exports = async function (msg) {
  if (msg.channel.id === process.env.CHANNEL_ID) {
    if (msg.content.substring(0, 3) === "!CS") {
      await exec("a " + msg.content.substring(3), (error, stdout, stderr) =>
        getMessage(msg, stdout)
      );
    }
  }
};

function getMessage(msg, resp) {
  //console.log(resp);
  let content = msg.content.split(" ");
  if (content[1] === "help") {
    commands["help"](msg, resp);
  } else if (content[1] === "compare") {
    commands["compare"](msg, resp);
  } else if (content[1] === "pay") {
    commands["pay"](msg, resp);
  } else if (content[1] === "evaluate") {
    commands["evaluate"](msg, resp);
  }
}
