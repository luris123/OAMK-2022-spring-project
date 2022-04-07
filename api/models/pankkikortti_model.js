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
  getAllInfo: function (kortinnumero, callback) {
    return db.query(
      "SELECT tili.id_tili, asiakas.id_asiakas, nimi, debitTilinumero, creditTilinumero, debitSaldo, creditSaldo FROM pankkikortti INNER JOIN tili ON pankkikortti.id_Tili = tili.id_Tili INNER JOIN asiakas ON pankkikortti.id_Asiakas = asiakas.id_Asiakas WHERE kortinnumero = ?",
      [kortinnumero],
      callback
    );
  },
};

module.exports = pankkikortti;
