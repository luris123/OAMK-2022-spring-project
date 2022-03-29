const express = require("express");
const router = express.Router();
const pankkikortti = require("../models/pankkikortti_model");

router.get("/:id?", function (request, response) {
  if (request.params.id) {
    pankkikortti.getById(request.params.id, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    pankkikortti.getAll(function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});

router.post("/", function (request, response) {
  pankkikortti.add(request.body, function (err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

router.delete("/:id", function (request, response) {
  pankkikortti.delete(request.params.id, function (err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

router.put("/:id", function (request, response) {
  pankkikortti.update(
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
