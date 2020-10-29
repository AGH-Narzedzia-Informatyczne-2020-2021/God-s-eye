//for registering
// const User = require('../models/User');


module.exports.login_get = (req, res) => {
    res.render('login', { title: 'Sign in'});
}
module.exports.login_post = async (req, res) => {
    res.send('user login');
}