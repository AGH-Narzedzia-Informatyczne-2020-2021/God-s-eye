const express = require('express');

//create app
const app = express();

//lisen to 3000 port of localhost
app.listen(3000);

//give access to public files
app.use(express.static('public'));

//set view engine to ejs
app.set('view engine', 'ejs');

app.get('/', (req, res) =>{
    res.render('index', { title: 'Home'});
});

app.get('/login', (req, res) =>{
    res.render('login', { title: 'Sign in'});
});

//redirect every not matching request to 404 page
app.use((req, res) => {
    res.status(404).render('404', { title: '404' });
  });
  