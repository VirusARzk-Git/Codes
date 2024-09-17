// ES6

class User{
    constructor(username, email, password){
        this.username = username;
        this.email = email;
        this.password = password;
    }

    encryptPassword(){
        return `${this.password}123`;
    }
}

const user = new User('virus', 'virus@xyz.com', 'password');
console.log(user);
console.log(user.encryptPassword());



// But if you want to use the prototype method, you can do it like this:

function USER(username, email, password){
    this.username = username;
    this.email = email;
    this.password = password;
}

USER.prototype.encryptPassword = function(){
    return `${this.password}123`;
}

const user2 = new User('aditya', 'aditya@xyz.com', 'password');
console.log(user2);
console.log(user2.encryptPassword());