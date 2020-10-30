const express = require('express');
const mongoose = require('mongoose');
const authRoutes = require('./routes/authRoutes')

//create app
const app = express();

//connect to db
const dbURL = 'mongodb+srv://sebastian:test1234@testing.7zbkb.mongodb.net/node-auth';
mongoose.connect(dbURL, {useNewUrlParser: true, useUnifiedTopology: true})
    .then((result) => {
        console.log('conntected to db');
        app.listen(3000);
    })
    .catch((err) => console.log(err));


//give access to public files
app.use(express.static('public'));
//json 
app.use(express.json());


//set view engine to ejs
app.set('view engine', 'ejs');

app.get('/', (req, res) =>{
    // res.redirect('/login');
    res.render('index', { title: 'Home'});
});

app.use(authRoutes);

//redirect every not matching request to 404 page
app.use((req, res) => {
    res.status(404).render('404', { title: '404' });
  });
  