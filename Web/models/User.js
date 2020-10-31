//file for sign up
const mongoose = require('mongoose');

//hash password
const bcrypt = require('bcrypt');

//create userModelSchema for mongoose
const userSchema = new mongoose.Schema({
    email: {type: String},
    password: {type: String}
});

//static method to login user
userSchema.statics.login = async function(email, password){
    const user = await this.findOne({email: email});
    if(user) {
        const auth = await bcrypt.compare(password, user.password);
        if(auth)return user;
        else throw Error('incorrect password');
    }
    else throw Error('incorect email');
}

//static method to hash password
userSchema.statics.hash = async function(email, password){
    const salt = await bcrypt.genSalt();
    const hashed = await bcrypt.hash(password, salt);
    const user = await this.findOneAndUpdate({email: email}, {password: hashed}, {new: true});
    if(user) {
        return user;
    } else throw Error('incorect email');
}


//first model arg must be singular because mongoose takes it as plural and identify with db collection f.e users
const User = mongoose.model('user', userSchema);

module.exports = User;