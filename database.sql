-- MySQL dump 10.13  Distrib 8.0.27, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: banksimul
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `asiakas`
--

DROP TABLE IF EXISTS `asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas` (
  `id_Asiakas` int NOT NULL AUTO_INCREMENT,
  `nimi` varchar(45) NOT NULL,
  `lähiosoite` varchar(45) NOT NULL,
  `puhelinnumero` varchar(20) NOT NULL,
  PRIMARY KEY (`id_Asiakas`),
  UNIQUE KEY `id_Asiakas_UNIQUE` (`id_Asiakas`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `asiakkaat_ja_tilit`
--

DROP TABLE IF EXISTS `asiakkaat_ja_tilit`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakkaat_ja_tilit` (
  `id_Asiakas` int NOT NULL,
  `id_Tili` int NOT NULL,
  PRIMARY KEY (`id_Asiakas`,`id_Tili`),
  KEY `fk_Tili_has_Asiakas_Asiakas1_idx` (`id_Asiakas`),
  KEY `fk_Tili_has_Asiakas_Tili1_idx` (`id_Tili`),
  CONSTRAINT `Asiakas_id_Asiakas` FOREIGN KEY (`id_Asiakas`) REFERENCES `asiakas` (`id_Asiakas`),
  CONSTRAINT `Tili_id_Tili` FOREIGN KEY (`id_Tili`) REFERENCES `tili` (`id_Tili`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakkaat_ja_tilit`
--

LOCK TABLES `asiakkaat_ja_tilit` WRITE;
/*!40000 ALTER TABLE `asiakkaat_ja_tilit` DISABLE KEYS */;
/*!40000 ALTER TABLE `asiakkaat_ja_tilit` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pankkikortti`
--

DROP TABLE IF EXISTS `pankkikortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pankkikortti` (
  `id_Pankkikortti` int NOT NULL AUTO_INCREMENT,
  `kortinnumero` varchar(45) NOT NULL,
  `pinkoodi` varchar(200) NOT NULL,
  `id_Asiakas` int NOT NULL,
  `id_Tili` int NOT NULL,
  PRIMARY KEY (`id_Pankkikortti`),
  UNIQUE KEY `id_Pankkikortti_UNIQUE` (`id_Pankkikortti`),
  KEY `idAsiakas_idx` (`id_Asiakas`),
  KEY `id_Tili_idx` (`id_Tili`),
  CONSTRAINT `id_Asiakas` FOREIGN KEY (`id_Asiakas`) REFERENCES `asiakas` (`id_Asiakas`) ON DELETE CASCADE,
  CONSTRAINT `id_Tili` FOREIGN KEY (`id_Tili`) REFERENCES `tili` (`id_Tili`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkikortti`
--

LOCK TABLES `pankkikortti` WRITE;
/*!40000 ALTER TABLE `pankkikortti` DISABLE KEYS */;
/*!40000 ALTER TABLE `pankkikortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tili`
--

DROP TABLE IF EXISTS `tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tili` (
  `id_Tili` int NOT NULL AUTO_INCREMENT,
  `debitTilinumero` varchar(45) NOT NULL,
  `creditTilinumero` varchar(45) DEFAULT NULL,
  `debitSaldo` float unsigned NOT NULL,
  `creditSaldo` float DEFAULT NULL,
  `luottoraja` float DEFAULT NULL,
  PRIMARY KEY (`id_Tili`),
  UNIQUE KEY `id_Tili_UNIQUE` (`id_Tili`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tili`
--

LOCK TABLES `tili` WRITE;
/*!40000 ALTER TABLE `tili` DISABLE KEYS */;
/*!40000 ALTER TABLE `tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tilitapahtumat`
--

DROP TABLE IF EXISTS `tilitapahtumat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tilitapahtumat` (
  `id_Tilitapahtumat` int NOT NULL AUTO_INCREMENT,
  `tilinumero` varchar(45) NOT NULL,
  `kortinnumero` varchar(45) NOT NULL,
  `pvm_ja_kellonaika` datetime NOT NULL,
  `tapahtuma` varchar(45) NOT NULL,
  `summa` float NOT NULL,
  `id_Tili` int NOT NULL,
  PRIMARY KEY (`id_Tilitapahtumat`),
  UNIQUE KEY `id_Tilitapahtumat_UNIQUE` (`id_Tilitapahtumat`),
  KEY `id_tili_idx` (`id_Tili`),
  CONSTRAINT `Tilitapahtumat_id_tili` FOREIGN KEY (`id_Tili`) REFERENCES `tili` (`id_Tili`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tilitapahtumat`
--

LOCK TABLES `tilitapahtumat` WRITE;
/*!40000 ALTER TABLE `tilitapahtumat` DISABLE KEYS */;
/*!40000 ALTER TABLE `tilitapahtumat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'banksimul'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-03-29 10:33:08
