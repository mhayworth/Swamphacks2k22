const { MessageEmbed } = require("discord.js");

module.exports = async function (msg, resp) {
  let embed = new MessageEmbed()
    .setTitle("Help")
    .setColor("#50C16B")
    .setDescription(resp);
  msg.channel.send({ embeds: [embed] });
};
