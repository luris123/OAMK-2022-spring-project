const express = require('express');
const router = express.Router();
const procedures = require('../models/procedures_model');

router.get('/:id/:tilinumero/:kortinnumero/:debitSaldo/:nostoSumma',
 function(request, response) {
  if (request.params.id) {
    procedures.nostaRahaaDebit(request.params.id, request.params.tilinumero, request.params.kortinnumero, request.params.debitSaldo, request.params.nostoSumma,  function(err) {
      if (err) {
        response.send(err);
      } else {
        response.send("Debit nosto suoritettu");
      }
    });
  } 
});

router.get('/:id/:tilinumero/:kortinnumero/:creditSaldo/:luottoraja:/nostoSumma',
 function(request, response) {
  if (request.params.id) {
    procedures.nostaRahaaCredit(request.params.id, request.params.tilinumero, request.params.kortinnumero, request.params.creditSaldo,request.params.luottoraja, request.params.nostoSumma,  function(err) {
      if (err) {
        response.send(err);
      } else {
        response.send("Credit nosto suoritettu");
      }
    });
  } 
});

module.exports = router;