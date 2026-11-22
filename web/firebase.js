
// Firebase configuration
const firebaseConfig = {
    apiKey: "AIzaSyCjHIaxA8SJm4WBg8zUatP60a36ysA51Ys",
    authDomain: "internmatch-e7baa.firebaseapp.com",
    projectId: "internmatch-e7baa",
    storageBucket: "internmatch-e7baa.firebasestorage.app",
    messagingSenderId: "50156039306",
    appId: "1:50156039306:web:4e591596714685b1ecd173"
};

firebase.initializeApp(firebaseConfig);

const auth = firebase.auth();
const googleProvider = new firebase.auth.GoogleAuthProvider();

window.firebaseAuth = auth;
window.googleProvider = googleProvider;

window.firebaseReady = auth.setPersistence(
    firebase.auth.Auth.Persistence.LOCAL
);
