const User = require('../models/User');
const Data = require('../models/Data');

const jwt = require('jsonwebtoken');


const maxAge = 24*60*60;
const createToken = (id) =>{
    return jwt.sign({id}, 'my secret', {
        expiresIn: maxAge
    });
};

module.exports.data_get = (req, res) => {
    res.render('data', { title: 'Data'});
};
module.exports.data_post = async (req, res) =>{
    const {data1, data2} = req.body;
    try {
        const record = await Data.create({data1, data2});
        res.status(200).json(record);
    }
    catch (err) {
        res.status(400).json({err});;
    }
};

module.exports.login_get = (req, res) => {
    res.render('login', { title: 'Sign in'});
};
module.exports.login_post = async (req, res) => {
    const { email, password } = req.body;
    try {
        const user = await User.login(email, password);
        const token = createToken(user._id);
        res.cookie('jwt', token, {httpOnly: true, maxAge: maxAge*1000});
        res.status(200).json({user: user._id});
    }
    catch (err) {
        res.status(400).json({err});
    }
};
module.exports.password_get = (req, res) => {
    res.render('password', { title: 'Hash it'});
};
module.exports.password_post = async (req, res) => {
    const { email, password } = req.body;
    try {
        const user = await User.password(email, password);
        const token = createToken(user._id);
        res.cookie('jwt', token, {httpOnly: true, maxAge: maxAge*1000});
        res.status(201).json({user: user._id});
    }
    catch (err) {
        res.status(400).json({err});
    }
};
module.exports.logout_get = (req, res) =>{
    res.cookie('jwt', '', {maxAge: 1});
    res.redirect('/login');
}