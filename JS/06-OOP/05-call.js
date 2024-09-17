function setUsername(name) {
    this.username = name;
}

function createUser(username, email) {
    // setUsername(this, username);
    setUsername.call(this, username);
    this.email = email;
}

const user = new createUser('John Doe', 'john@example.com', 'password');
console.log(user);

