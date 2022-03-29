const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'banksimuluser',
  password: 'netpass',
  database: 'banksimul'
});
module.exports = connection;