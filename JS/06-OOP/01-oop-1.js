const user = {
    username: 'virus',
    loginCount: 14,
    signedIn: true,

    getUserDetails: function () {
        console.log(`Username: ${this.username}, Login Count: ${this.loginCount}, Signed In: ${this.signedIn}`);
        console.log(this);
    }
}

// console.log(user.username); // virus
// console.log(user.loginCount); // 14
// console.log(user.signedIn); // true
user.getUserDetails();