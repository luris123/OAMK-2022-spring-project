const db = require("../database");
const bcrypt = require("bcryptjs");

const saltRounds = 10;
const pankkikortti = {
  getAll: function (callback) {
    return db.query("select * from pankkikortti", callback);
  },
  getById: function (id, callback) {
    return db.query(
      "select * from pankkikortti where id_pankkikortti=?",
      [id],
      callback
    );
  },
  add: function (pankkikortti, callback) {
    bcrypt.hash(pankkikortti.pinkoodi, saltRounds, function (err, hash) {
      return db.query(
        "insert into pankkikortti (kortinnumero, pinkoodi, id_Asiakas, id_tili) values(?,?,?,?)",
        [
          pankkikortti.kortinnumero,
          hash,
          pankkikortti.id_Asiakas,
          pankkikortti.id_tili,
        ],
        callback
      );
    });
  },
  delete: function (id, callback) {
    return db.query(
      "delete from pankkikortti where id_pankkikortti=?",
      [id],
      callback
    );
  },
  update: function (id, pankkikortti, callback) {
    bcrypt.hash(pankkikortti.password, saltRounds, function (err, hash) {
      return db.query(
        "update pankkikortti set kortinnumero=?, pinkoodi=? where id_pankkikortti=?",
        [
          pankkikortti.kortinnumero,
          hash,
          id,
          pankkikortti.id_Asiakas,
          pankkikortti.id_tili,
        ],
        callback
      );
    });
  },
};

module.exports = pankkikortti;
