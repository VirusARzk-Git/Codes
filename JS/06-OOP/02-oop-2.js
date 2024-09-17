function User(username, loginCount, signedIn) {
    this.username = username;
    this.loginCount = loginCount;
    this.signedIn = signedIn;

    this.getUserDetails = function () {
        console.log(`Username: ${this.username}, Login Count: ${this.loginCount}, Signed In: ${this.signedIn}`);
        console.log(this);
    }
}

const user1 = new User('virus', 14, true);
const user2 = new User('Aditya', 20, false);

user1.getUserDetails();
user2.getUserDetails();