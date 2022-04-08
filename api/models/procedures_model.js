const db = require('../database');

const procedures = {
    nostaRahaaDebit: function(id, tilinumero, kortinnumero, debitSaldo, nostoSumma, callback) {
      return db.query('call nostaRahaaDebit(?,?,?,?,?)',
       [id, tilinumero, kortinnumero, debitSaldo, nostoSumma], callback);
    }
  };

module.exports = procedures;