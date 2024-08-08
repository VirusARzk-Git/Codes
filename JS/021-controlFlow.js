const isUserLoggedIn = true;

if (isUserLoggedIn) {
    console.log('User is logged in');
}

// Output: User is logged in

const temperature = 40, isRaining = true;
if (temperature > 30 && isRaining === false)
    console.log('It is hot outside');
else
    console.log('It is cold outside');

if(temperature > 30 || isRaining === false)
    console.log('It is hot outside');
else
    console.log('It is cold outside');