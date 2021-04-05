#!/usr/bin/node
const request = require('request');
const ID = process.argv[2];

request({ url: ('https://swapi-api.hbtn.io/api/films/' + ID), json: true }, function (err, res, json) {
  if (err) {
    return console.log(err);
  }
  for (const k of json.characters) {
    request({ url: k, json: true }, function (err, res, json) {
      if (err) {
        return console.log(err);
      }
      console.log(json.name);
    });
  }
});
