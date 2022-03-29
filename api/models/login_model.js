const db = require("../database");

const login = {
  checkPassword: function (kortinnumero, callback) {
    return db.query(
      "SELECT pinkoodi FROM pankkikortti WHERE kortinnumero = ?",
      [kortinnumero],
      callback
    );
  },
};

module.exports = login;
