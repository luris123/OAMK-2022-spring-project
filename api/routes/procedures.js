const express = require('express');
const router = express.Router();
const procedures = require('../models/procedures_model');

router.get('/talletus/:id/:tilityyppi/:tilinumero/:kortinnumero/:talletussumma',
 function(request, response) {
  if (request.params.id) {
    procedures.talletaRahaa(request.params.id, request.params.tilityyppi, request.params.tilinumero, request.params.kortinnumero, request.params.talletussumma, function(err) {
      if (err) {
        response.send(err);
      } else {
        response.send("talletus suoritettu");
      }
      
    });
  } 
});

router.get('/nosto/:id/:tilinumero/:kortinnumero/:debitSaldo/:nostoSumma',
 function(request, response, next) {
  if (request.params.id) {
    procedures.nostaRahaaDebit(request.params.id, request.params.tilinumero, request.params.kortinnumero, request.params.debitSaldo, request.params.nostoSumma,  function(err) {
      if (err) {
        response.send(err);
        
      } else {
        response.send("Debit nosto suoritettu");
        
      }
      next();
    });
  } 
});

router.get('/nosto/:id/:tilinumero/:kortinnumero/:creditSaldo/:nostoSumma/:luottoraja',
 function(request, response) {
  if (request.params.id) {
    procedures.nostaRahaaCredit(request.params.id, request.params.tilinumero, request.params.kortinnumero, request.params.creditSaldo, request.params.nostoSumma,request.params.luottoraja, function(err) {
      if (err) {
        response.send(err);
      } else {
        response.send("Credit nosto suoritettu");
      }
    });
  } 
});

router.get('/selaa/:id/:maara/:hakumaara', 
  function(request, response) {
  if (request.params.id) {
    procedures.selaaTapahtumat(request.params.id, request.params.maara, request.params.hakumaara, function(err, dbResult){
      if (err) {
        response.send(err);
      } else {
        response.send(dbResult[0]);
      }
    });
  }
});

module.exports = router;