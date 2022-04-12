const db = require('../database');

const procedures = {
    nostaRahaaDebit: function(id, tilinumero, kortinnumero, debitSaldo, nostoSumma, callback) {
      return db.query('call nostaRahaaDebit(?,?,?,?,?)',
       [id, tilinumero, kortinnumero, debitSaldo, nostoSumma], callback);
    },

    nostaRahaaCredit: function(id, tilinumero, kortinnumero, creditSaldo, nostoSumma, luottoraja, callback) {
      return db.query('call nostaRahaaCredit(?,?,?,?,?,?)',
       [id, tilinumero, kortinnumero, creditSaldo, nostoSumma, luottoraja], callback);
    },

    talletaRahaa: function(id, tilityyppi, tilinumero, kortinnumero, talletussumma, callback) {
      return db.query('call talletaRahaa(?,?,?,?,?)',
       [id, tilityyppi, tilinumero, kortinnumero, talletussumma], callback);
    }


  };

module.exports = procedures;