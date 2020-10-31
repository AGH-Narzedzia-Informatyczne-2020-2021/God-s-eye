const { Router } = require('express');
const authController = require('../controllers/authController'); //import control functions



const router = Router();

router.get('/login', authController.login_get);
router.post('/login', authController.login_post);
router.get('/hash', authController.hash_get);
router.post('/hash', authController.hash_post);



module.exports = router;