function User(email, password)
{
    this._email = email;
    this._password = password;

    Object.defineProperty(this, 'email', {
        get: function () {
            return `${this._email}`;
        },
        set: function (newEmail) {
            this._email = newEmail;
        }
    });
}

const aditya = new User('Aditya@google.com', 'Abc@123');
console.log(aditya);
