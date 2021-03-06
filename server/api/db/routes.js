var express = require('express');
var router = express.Router();
var collections = require('./collections/controller.js');
var descriptors = require('./descriptors/controller.js');
router.get('/collections',collections.list);
router.get('/collections/:collection',collections.printData);
router.get('/collections/:collection/download/:fileType',collections.download);
router.get('/descriptors',descriptors.listDescriptor);
router.get('/descriptors/:descriptor',descriptors.getDescriptor);
router.put('/descriptors/:descriptor',descriptors.updateDescriptor);
router.delete('/descriptors/:descriptor',descriptors.deleteMap);
module.exports = router;
