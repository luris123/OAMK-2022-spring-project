const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'i54jns50s3z6gbjt.chr7pe7iynqr.eu-west-1.rds.amazonaws.com',
  user: 'nruoa1u7gp4j1xjs',
  password: 'clsjcpxzksowk0cc',
  database: 'f4wbmdmg31nr0iri'
});
module.exports = connection;
