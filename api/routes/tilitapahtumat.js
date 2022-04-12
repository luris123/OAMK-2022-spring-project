const express = require("express");
const router = express.Router();
const tilitapahtumat = require("../models/tilitapahtumat_model");

router.get("/:id?", function (request, response) {
  if (request.params.id) {
    tilitapahtumat.getById(request.params.id, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    tilitapahtumat.getAll(function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});

router.get("/omistaja/:id_tili/:maara/:hakumaara", function (request, response) {
  if (request.params.id_tili) {
    tilitapahtumat.getByidTili(request.params.id_tili, request.params.maara, request.params.hakumaara, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
})

router.post("/", function (request, response) {
  tilitapahtumat.add(request.body, function (err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.delete("/:id", function (request, response) {
  tilitapahtumat.delete(request.params.id, function (err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.put("/:id", function (request, response) {
  tilitapahtumat.update(
    request.params.id,
    request.body,
    function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    }
  );
});

module.exports = router;
