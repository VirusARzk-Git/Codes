class User {
    constructor(email, password) {
        this.email = email;
        this.password = password
    }

    get email() {
        return `${this._email}`
    }

    set email(newEmail) {
        this._email = newEmail;
    }

    // Getter
    get password() {
        return `${this._password}`
    }
    // Setter
    set password(newPassword) {
        this._password = newPassword.toUpperCase();
    }
}

const aditya = new User('adi@tya.in', 'Abc@123');
console.log(aditya);