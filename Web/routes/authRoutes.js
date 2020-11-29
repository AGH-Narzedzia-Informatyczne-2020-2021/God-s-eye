const { Router } = require('express');
const authController = require('../controllers/authController'); //import control functions
const {requireAuth} = require('../middleware/authMiddleware');


const router = Router();

router.get('/login', authController.login_get);
router.post('/login', authController.login_post);
router.get('/password', requireAuth, authController.password_get);
router.post('/password', authController.password_post);
router.get('/logout', authController.logout_get);
router.get('/data', authController.data_get);
router.post('/data', authController.data_post);




module.exports = router;