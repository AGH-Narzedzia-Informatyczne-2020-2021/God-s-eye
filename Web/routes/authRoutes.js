const { Router } = require('express');
const authController = require('../controllers/authController'); //import control functions



const router = Router();

router.get('/login', authController.login_get);
router.post('/login', authController.login_post);


module.exports = router;