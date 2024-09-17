class User {
    constructor(username) {
        this.username = username;
    }

    logMe() {
        console.log(`Hi, ${this.username}`);
    }

    static createId() {
        return Math.floor(Math.random() * 1000);
    }
}


const u1 = new User('Virus');
u1.logMe();
// console.log(u1.createId());

class Admin extends User {
    constructor(username, email) {
        super(username);
        this.email = email;
    }
}

const iphone = new Admin('iPhone', 'i@fone.com');
console.log(iphone);
iphone.logMe();
// console.log(iphone.createId());

console.log(Admin.createId());