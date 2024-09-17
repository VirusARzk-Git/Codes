function multiplyByFive(num) {
    return num * 5;
}

multiplyByFive.power = 2;

console.log(multiplyByFive(2));
console.log(multiplyByFive.power);
console.log(multiplyByFive);


function createUser(username, score) {
    this.username = username;
    this.score = score;
}

createUser.prototype.increment = function () {
    this.score++;
}

createUser.prototype.getUserDetails = function () {
    console.log(`Username: ${this.username}, Score: ${this.score}`);
}

const user1 = new createUser('virus', 15);
const user2 = new createUser('Aditya', 20);

user1.increment();
user1.getUserDetails();

user2.getUserDetails();
console.log(user1);
console.log(user2);

