<<<<<<< HEAD
var express = require('express');
var router = express.Router();
var controller = require('./controller.js');
router.get('/collections',controller.list);
router.get('/collections/:collection',controller.printData);
module.exports = router;
=======
>>>>>>> Revert "added a new api to get db requests from the server"
