class Person {
    constructor(name) {
        this.name = name;
    }

    logMessage() {
        console.log(`Hi, ${this.name}`);
    }
}

class Teacher extends Person {
    constructor(name, subject) {
        super(name);
        this.subject = subject;
    }

    teach() {
        console.log(`I am ${this.name}, I teach ${this.subject}`);
    }
}

const u1 = new Person('John Doe');
u1.logMessage();

const t1 = new Teacher('Jane Doe', 'Maths');
t1.logMessage();
t1.teach();

console.log(t1 instanceof Teacher);