const { Router } = require('express');
const authController = require('../controllers/authController'); //import control functions
const {requireAuth} = require('../middleware/authMiddleware');


const router = Router();

router.get('/login', authController.login_get);
router.post('/login', authController.login_post);
router.get('/hash', requireAuth, authController.hash_get);
router.post('/hash', authController.hash_post);
router.get('/logout', authController.logout_get);



module.exports = router;