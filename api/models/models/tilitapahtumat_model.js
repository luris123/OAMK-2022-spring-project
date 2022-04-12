const db = require("../database");

const tilitapahtumat = {
  getById: function (id, callback) {
    return db.query(
      "select * from tilitapahtumat where id_tilitapahtumat=?",
      [id],
      callback
    );
  },
  getAll: function (callback) {
    return db.query("select * from tilitapahtumat", callback);
  },
  add: function (tilitapahtumat, callback) {
    return db.query(
      "insert into tilitapahtumat (tilinumero,kortinnumero,pvm_ja_kellonaika,tapahtuma,summa,id_tili) values(?,?,?,?,?,?)",
      [
        tilitapahtumat.tilinumero,
        tilitapahtumat.kortinnumero,
        tilitapahtumat.pvm_ja_kellonaika,
        tilitapahtumat.tapahtuma,
        tilitapahtumat.summa,
        tilitapahtumat.id_tili,
      ],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query(
      "delete from tilitapahtumat where id_tilitapahtumat=?",
      [id],
      callback
    );
  },
  update: function (id, tilitapahtumat, callback) {
    return db.query(
      "update tilitapahtumat set tilinumero=?,kortinnumero=?, pvm_ja_kellonaika=?, tapahtuma=?, summa=?, id_tili=? where id_tilitapahtumat=?",
      [
        tilitapahtumat.tilinumero,
        tilitapahtumat.kortinnumero,
        tilitapahtumat.pvm_ja_kellonaika,
        id,
        tilitapahtumat.tapahtuma,
        tilitapahtumat.summa,
        tilitapahtumat.id_tili,
      ],
      callback
    );
  },
};
module.exports = tilitapahtumat;
