const db = require("../database");

const tili = {
  getById: function (id, callback) {
    return db.query("select * from tili where id_tili=?", [id], callback);
  },
  getAll: function (callback) {
    return db.query("select * from tili", callback);
  },
  add: function (tili, callback) {
    return db.query(
      "insert into tili (debitTilinumero,creditTilinumero,debitSaldo,creditSaldo,luottoraja) values(?,?,?,?,?)",
      [
        tili.debitTilinumero,
        tili.creditTilinumero,
        tili.debitSaldo,
        tili.creditSaldo,
        tili.luottoraja,
      ],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query("delete from tili where id_tili=?", [id], callback);
  },
  update: function (id, tili, callback) {
    return db.query(
      "update tili set debitTilinumero=?,creditTilinumero=?, debitSaldo=?, creditSaldo=?, luottoraja=? where id_tili=?",
      [
        tili.debitTilinumero,
        tili.creditTilinumero,
        tili.debitSaldo,
        id,
        tili.creditSaldo,
        tili.luottoraja,
      ],
      callback
    );
  },
};
module.exports = tili;
