// fetch('https://jsonplaceholder.typicode.com/users') // fetch returns a promise
//     .then(response => response.json()) // response.json() returns a promise
//     .then(data => console.log(data)) // data is the result of the promise
//     .catch(error => console.error(error)); // catch errors

// fetch('https://something.com').then().catch().finally();

const promiseOne = new Promise((resolve, reject) => {
    setTimeout(() => {
        console.log('Async task 1 is done');
        resolve();
    }, 1000);
});

promiseOne.then(() => {
    console.log('Promise 1 resolved');
});

new Promise((resolve, reject) => {
    setTimeout(() => {
        console.log('Async task 2 is done');
        resolve();
    }, 1000);
}).then(() => {
    console.log('Promise 2 resolved');
});

const promiseThree = new Promise((resolve, reject) => {
    setTimeout(() => {
        resolve({ username: 'Virus', name: 'Aditya' });
    }, 1000);
});

promiseThree.then(data => {
    console.log(data);
});

const promiseFour = new Promise((resolve, reject) => {
    setTimeout(() => {
        let error = false;
        if (!error) {
            resolve({ Name: 'Aditya', age: 21 });
        }
        else
            reject('Something went wrong');
    }, 1000);
});

promiseFour.then(data => {
    console.log(data);
    return data.Name;
}).then(data => {
    console.log(data);
}).catch(error => {
    console.error(error);
}).finally(() => {
    console.log('Promise 4 is done');
});

const promiseFive = new Promise((resolve, reject) => {
    setTimeout(() => {
        let error = true;
        if (!error)
            resolve('Promise 5 resolved');
        else
            reject('Promise 5 rejected');
    }, 1000);
});

async function consumePromiseFive() {
    try {
        const response = await promiseFive;
        console.log(response);
    }
    catch (error) {
        console.error(error);
    }
    finally {
        console.log('Promise 5 is done');
    }
}

consumePromiseFive();


async function fetchUsers() {
    try {
        const response = await fetch('https://jsonplaceholder.typicode.com/users')
        const data = await response.json()
        console.log(data);
    }
    catch (error) {
        console.log("Error: ", error);
    }
    finally {
        console.log('Fetching is done');
    }
}

fetchUsers();


fetch('https://jsonplaceholder.typicode.com/users')
    .then(response => response.json())
    .then(data => console.log(data))
    .catch(error => console.error(error));