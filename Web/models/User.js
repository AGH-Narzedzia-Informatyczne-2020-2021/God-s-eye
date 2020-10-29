//file for sign up
const mongoose = require('mongoose');

//create userModelSchema for mongoose
const userSchema = new mongoose.Schema({
    email: {
        type: String,
        required: true,
        unique: true,
        lowercase: true
    },
    password: {
        type: String,
        required: true,
        minlength: 6
    }
});

//first model arg must be singular because mongoose takes it as plural and identify with db collection f.e users
const User = mongoose.model('user', userSchema);

module.exports = User;