const { MessageEmbed } = require("discord.js");

module.exports = async function (msg, resp) {
  const embed = new MessageEmbed()
    .setTitle("Pay")
    .setColor("#50C16B")
    .setDescription(resp);
  msg.channel.send({ embeds: [embed] });
};
