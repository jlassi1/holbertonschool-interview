#!/usr/bin/node
const request = require('request');
const id = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + id;

request(url, { json: true }, (err, res, body) => {
  if (err) {
    return console.log(err);
  }

  const names = [];

  body.characters.forEach(element => {
    const id = element.split('/')[5];
    request(element, { json: true }, (err, res, body) => {
      if (err) {
        return console.log(err);
      }
      names[id] = body.name;
    });
  });

  setTimeout(function () {
    body.characters.forEach(element => {
      const id = element.split('/')[5];
      console.log(names[id]);
    });
  }, 2000);
});
