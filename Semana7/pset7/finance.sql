-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Host: db
-- Tempo de geração: 14-Abr-2021 às 21:58
-- Versão do servidor: 5.7.33
-- versão do PHP: 7.4.16

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `finance`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `stocks`
--

CREATE TABLE `stocks` (
  `stockId` int(10) UNSIGNED NOT NULL,
  `userId` int(10) UNSIGNED NOT NULL,
  `symbol` varchar(10) NOT NULL,
  `shares` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `stocks`
--

INSERT INTO `stocks` (`stockId`, `userId`, `symbol`, `shares`) VALUES
(3, 3, 'IBM', 400),
(4, 4, 'NKE', 1120),
(6, 1, 'NKE', 300),
(27, 4, 'DISCB', 100),
(28, 4, 'AMZN', 10);

-- --------------------------------------------------------

--
-- Estrutura da tabela `trades`
--

CREATE TABLE `trades` (
  `id` int(10) UNSIGNED NOT NULL,
  `userId` int(10) UNSIGNED NOT NULL,
  `type` varchar(10) NOT NULL,
  `symbol` varchar(10) NOT NULL,
  `shares` int(10) UNSIGNED NOT NULL,
  `price` varchar(10) NOT NULL,
  `date` timestamp NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `trades`
--

INSERT INTO `trades` (`id`, `userId`, `type`, `symbol`, `shares`, `price`, `date`) VALUES
(1, 4, 'BUY', 'AAPL', 100, '134', '2021-04-13 20:42:56'),
(10, 4, 'BUY', 'DISCB', 100, '97.05', '2021-04-14 20:01:56'),
(11, 4, 'BUY', 'AMZN', 10, '3332.93', '2021-04-14 21:20:24');

-- --------------------------------------------------------

--
-- Estrutura da tabela `users`
--

CREATE TABLE `users` (
  `uid` int(10) UNSIGNED NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `cash` decimal(65,4) UNSIGNED NOT NULL DEFAULT '0.0000'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Extraindo dados da tabela `users`
--

INSERT INTO `users` (`uid`, `username`, `password`, `cash`) VALUES
(1, 'lemon', 'helloworld', '10000.0000'),
(2, 'luke', 'skywalker1', '10000.0000'),
(3, 'leia', 'skywalker2', '10000.0000'),
(4, 'pskroob', '12345', '18370.5000'),
(6, 'teste', '123', '10000.0000');

--
-- Índices para tabelas despejadas
--

--
-- Índices para tabela `stocks`
--
ALTER TABLE `stocks`
  ADD PRIMARY KEY (`stockId`),
  ADD UNIQUE KEY `userId` (`userId`,`symbol`),
  ADD KEY `userIdFK` (`userId`) USING BTREE;

--
-- Índices para tabela `trades`
--
ALTER TABLE `trades`
  ADD PRIMARY KEY (`id`),
  ADD KEY `userIdFK` (`userId`);

--
-- Índices para tabela `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`uid`),
  ADD UNIQUE KEY `username` (`username`);

--
-- AUTO_INCREMENT de tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `stocks`
--
ALTER TABLE `stocks`
  MODIFY `stockId` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=29;

--
-- AUTO_INCREMENT de tabela `trades`
--
ALTER TABLE `trades`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT de tabela `users`
--
ALTER TABLE `users`
  MODIFY `uid` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- Restrições para despejos de tabelas
--

--
-- Limitadores para a tabela `stocks`
--
ALTER TABLE `stocks`
  ADD CONSTRAINT `stocks_ibfk_1` FOREIGN KEY (`userId`) REFERENCES `users` (`uid`);

--
-- Limitadores para a tabela `trades`
--
ALTER TABLE `trades`
  ADD CONSTRAINT `trades_ibfk_1` FOREIGN KEY (`userId`) REFERENCES `users` (`uid`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
