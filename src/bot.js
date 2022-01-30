console.log("beep beep! 🤖");
require("dotenv").config();

const { Client, Intents, Message, MessageEmbed } = require("discord.js");

const client = new Client({
  intents: [Intents.FLAGS.GUILDS, Intents.FLAGS.GUILD_MESSAGES],
});

const commandHandler = require("./commands");

// Logging into bot
client.login(process.env.BOT_TOKEN);

// confirming bot is ready to run
client.on("ready", readyDiscord);

// reading user message
client.on("message", commandHandler);

// Code function
function readyDiscord() {
  console.log("<3");
}
