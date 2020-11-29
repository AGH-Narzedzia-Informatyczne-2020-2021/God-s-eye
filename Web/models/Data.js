const mongoose = require('mongoose');

const dataSchema = new mongoose.Schema({
    data1: {type: String},
    data2: {type: String}
});

const Data = mongoose.model('data', dataSchema);

module.exports = Data;