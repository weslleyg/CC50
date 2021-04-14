<?

    // require common code
    require_once("includes/common.php");

?>

<!DOCTYPE html>

<html>

  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link href="https://unpkg.com/tailwindcss@^2/dist/tailwind.min.css" rel="stylesheet">
    <title>CC50 Finanças: Home</title>
  </head>

  <body>

    <div class="min-h-screen flex flex-col flex-auto flex-shrink-0 antialiased bg-gray-50 text-gray-800">
    
    <div class="fixed flex flex-col top-0 left-0 w-64 bg-gray-900 h-full shadow-lg">
        <div class="flex items-center pl-6 h-20 border-b border-gray-800">
            <? $result = mysqli_query($connection, "SELECT username, cash FROM users WHERE uid = {$_SESSION["uid"]}"); ?>
            <!-- <? $row = mysqli_fetch_array($result); ?> -->
            <div class="ml-1">
                <p class="ml-1 text-md font-medium tracking-wide truncate text-gray-100 font-sans"><?= $row["username"] ?></p>
                <div class="badge">
                    <span class="px-2 py-0.5 ml-auto text-xs font-medium tracking-wide text-blue-800 bg-blue-100 rounded-full">$ <?= $row["cash"] ?></span>
                </div>
            </div>
        </div>
        <div class="overflow-y-auto overflow-x-hidden flex-grow">
        <ul class="flex flex-col py-6 space-y-1">
            <li class="px-5">
                <div class="flex flex-row items-center h-8">
                    <div class="flex font-semibold text-sm text-gray-300 my-4 font-sans uppercase">Account</div>
                </div>
            </li>
            <li>
                <a href="index.php" class="relative flex flex-row items-center h-11 focus:outline-none hover:bg-gray-700 text-gray-500 hover:text-gray-200 border-l-4 border-transparent hover:border-blue-500 pr-6">
                    <span class="inline-flex justify-center items-center ml-4">
                    <svg class="w-5 h-5" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M3 12l2-2m0 0l7-7 7 7M5 10v10a1 1 0 001 1h3m10-11l2 2m-2-2v10a1 1 0 01-1 1h-3m-6 0a1 1 0 001-1v-4a1 1 0 011-1h2a1 1 0 011 1v4a1 1 0 001 1m-6 0h6"></path></svg>
                    </span>
                    <span class="ml-2 font-semibold text-sm tracking-wide truncate font-sans">Home</span>
                </a>
            </li>
            <li>
                <a href="deposit.php" class="relative flex flex-row items-center h-11 focus:outline-none hover:bg-gray-700 text-gray-500 hover:text-gray-200 border-l-4 border-transparent hover:border-blue-500 pr-6">
                    <span class="inline-flex justify-center items-center ml-4">
                    <svg class="w-5 h-5" viewBox="0 0 24 24"><path fill="currentColor" d="M15 15V17H18V20H20V17H23V15H20V12H18V15M14.97 11.61C14.85 10.28 13.59 8.97 12 9C10.3 9.03 9 10.3 9 12C9 13.7 10.3 14.94 12 15C12.38 15 12.77 14.92 13.14 14.77C13.41 13.67 13.86 12.63 14.97 11.61M13 16H7C7 14.9 6.11 14 5 14V10C6.11 10 7 9.11 7 8H17C17 9.11 17.9 10 19 10V10.06C19.67 10.06 20.34 10.18 21 10.4V6H3V18H13.32C13.1 17.33 13 16.66 13 16Z" /></svg>
                    </span>
                    <span class="ml-2 font-semibold text-sm tracking-wide truncate font-sans">Deposit</span>
                </a>
            </li>
            <li>
                <a href="quote.php" class="relative flex flex-row items-center h-11 focus:outline-none hover:bg-gray-700 text-gray-500 hover:text-gray-200 border-l-4 border-transparent hover:border-blue-500 pr-6">
                    <span class="inline-flex justify-center items-center ml-4">
                    <svg class="w-5 h-5" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg"><path fill="currentColor" d="M21 8C19.5 8 18.7 9.4 19.1 10.5L15.5 14.1C15.2 14 14.8 14 14.5 14.1L11.9 11.5C12.3 10.4 11.5 9 10 9C8.6 9 7.7 10.4 8.1 11.5L3.5 16C2.4 15.7 1 16.5 1 18C1 19.1 1.9 20 3 20C4.4 20 5.3 18.6 4.9 17.5L9.4 12.9C9.7 13 10.1 13 10.4 12.9L13 15.5C12.7 16.5 13.5 18 15 18C16.5 18 17.3 16.6 16.9 15.5L20.5 11.9C21.6 12.2 23 11.4 23 10C23 8.9 22.1 8 21 8M15 9L15.9 6.9L18 6L15.9 5.1L15 3L14.1 5.1L12 6L14.1 6.9L15 9M3.5 11L4 9L6 8.5L4 8L3.5 6L3 8L1 8.5L3 9L3.5 11Z" /></svg>
                    </span>
                    <span class="ml-2 font-semibold text-sm tracking-wide truncate font-sans">Quote</span>
                </a>
            </li>
            <li class="px-5">
            <div class="flex flex-row items-center h-8">
                <div class="flex font-semibold text-sm text-gray-300 my-4 font-sans uppercase">Manage</div>
            </div>
            </li>
            <li>
            <a href="history.php" class="relative flex flex-row items-center h-11 focus:outline-none hover:bg-gray-700 text-gray-500 hover:text-gray-200 border-l-4 border-transparent hover:border-blue-500 pr-6">
                <span class="inline-flex justify-center items-center ml-4">
                <svg class="w-5 h-5" viewBox="0 0 24 24"><path fill="currentColor" d="M17,9H7V7H17M17,13H7V11H17M14,17H7V15H14M12,3A1,1 0 0,1 13,4A1,1 0 0,1 12,5A1,1 0 0,1 11,4A1,1 0 0,1 12,3M19,3H14.82C14.4,1.84 13.3,1 12,1C10.7,1 9.6,1.84 9.18,3H5A2,2 0 0,0 3,5V19A2,2 0 0,0 5,21H19A2,2 0 0,0 21,19V5A2,2 0 0,0 19,3Z" /></svg>
               </span>
                <span class="ml-2 font-semibold text-sm tracking-wide truncate font-sans">Trades</span>
                <span class="px-2 py-0.5 ml-auto text-xs font-medium tracking-wide text-blue-500 bg-blue-100 rounded-full">New</span>
            </a>
            </li>
            <li>
            <a href="buy.php" class="relative flex flex-row items-center h-11 focus:outline-none hover:bg-gray-700 text-gray-500 hover:text-gray-200 border-l-4 border-transparent hover:border-blue-500 pr-6">
                <span class="inline-flex justify-center items-center ml-4">
                <svg class="w-5 h-5" viewBox="0 0 24 24"><path fill="currentColor" d="M11,9H13V6H16V4H13V1H11V4H8V6H11M7,18A2,2 0 0,0 5,20A2,2 0 0,0 7,22A2,2 0 0,0 9,20A2,2 0 0,0 7,18M17,18A2,2 0 0,0 15,20A2,2 0 0,0 17,22A2,2 0 0,0 19,20A2,2 0 0,0 17,18M7.17,14.75L7.2,14.63L8.1,13H15.55C16.3,13 16.96,12.59 17.3,11.97L21.16,4.96L19.42,4H19.41L18.31,6L15.55,11H8.53L8.4,10.73L6.16,6L5.21,4L4.27,2H1V4H3L6.6,11.59L5.25,14.04C5.09,14.32 5,14.65 5,15A2,2 0 0,0 7,17H19V15H7.42C7.29,15 7.17,14.89 7.17,14.75Z" /></svg>
                </span>
                <span class="ml-2 font-semibold text-sm tracking-wide truncate font-sans">Buy</span>
            </a>
            </li>
            <li>
            <a href="sell.php" class="relative flex flex-row items-center h-11 focus:outline-none hover:bg-gray-700 text-gray-500 hover:text-gray-200 border-l-4 border-transparent hover:border-blue-500 pr-6">
                <span class="inline-flex justify-center items-center ml-4">
                <svg class="w-5 h-5" viewBox="0 0 24 24"><path fill="currentColor" d="M14.12,8.53L12,6.41L9.88,8.54L8.46,7.12L10.59,5L8.47,2.88L9.88,1.47L12,3.59L14.12,1.46L15.54,2.88L13.41,5L15.53,7.12L14.12,8.53M7,18A2,2 0 0,1 9,20A2,2 0 0,1 7,22A2,2 0 0,1 5,20A2,2 0 0,1 7,18M17,18A2,2 0 0,1 19,20A2,2 0 0,1 17,22A2,2 0 0,1 15,20A2,2 0 0,1 17,18M7.17,14.75A0.25,0.25 0 0,0 7.42,15H19V17H7A2,2 0 0,1 5,15C5,14.65 5.09,14.32 5.25,14.04L6.6,11.59L3,4H1V2H4.27L5.21,4L6.16,6L8.4,10.73L8.53,11H15.55L18.31,6L19.41,4H19.42L21.16,4.96L17.3,11.97C16.96,12.59 16.3,13 15.55,13H8.1L7.2,14.63L7.17,14.75Z" /></svg>
                </span>
                <span class="ml-2 font-semibold text-sm tracking-wide truncate font-sans">Sell</span>
            </a>
            </li>
            <li>
            <a href="logout.php" class="relative flex flex-row items-center h-11 focus:outline-none hover:bg-gray-700 text-gray-500 hover:text-gray-200 border-l-4 border-transparent hover:border-red-500 pr-6">
                <span class="inline-flex justify-center items-center ml-4 text-red-400">
                <svg class="w-5 h-5" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M17 16l4-4m0 0l-4-4m4 4H7m6 4v1a3 3 0 01-3 3H6a3 3 0 01-3-3V7a3 3 0 013-3h4a3 3 0 013 3v1"></path></svg>
                </span>
                <span class="ml-2 font-semibold text-sm tracking-wide truncate font-sans">Logout</span>
            </a>
            </li>
        </ul>
        </div>
    </div>

    <div class="min-h-screen bg-gray-200 flex items-center px-4">
    <div class='overflow-x-auto w-full'>

        <!-- Table -->
        <table class='mx-auto max-w-4xl w-full whitespace-nowrap rounded-lg bg-white divide-y divide-gray-400 overflow-hidden'>
            <thead class="bg-gray-50">
                <tr class="text-gray-600 text-left">
                    <th class="font-semibold text-sm uppercase px-6 py-4">
                        Name
                    </th>
                    <th class="font-semibold text-sm uppercase px-6 py-4">
                        Price/Shares
                    </th>
                    <th class="font-semibold text-sm uppercase px-6 py-4 text-center">
                        Change
                    </th>
                    <th class="font-semibold text-sm uppercase px-6 py-4 text-center">
                        High
                    </th>
                    <th class="font-semibold text-sm uppercase px-6 py-4 text-center">
                        Low
                    </th>
                    <th class="font-semibold text-sm uppercase px-6 py-4 text-center">
                        Shares
                    </th>
                </tr>
            </thead>
            <tbody class="divide-y divide-gray-200">
                <? $result = mysqli_query($connection, "SELECT symbol, shares FROM stocks WHERE userId = {$_SESSION["uid"]}"); ?>
                <? while ($row = mysqli_fetch_array($result)): ?>
                <? $s = lookup($row["symbol"]); ?>
                <tr>
                    <td class="px-6 py-4">
                        <div class="flex items-center space-x-3">
                            <div>
                                <p class="">
                                    <?= $s->name ?>
                                </p>
                                <p class="text-gray-500 text-sm font-semibold tracking-wide">
                                    <?= $row["symbol"] ?>
                                </p>
                            </div>
                        </div>
                    </td>
                    <td class="px-6 py-4">
                        <p class="">
                            <?= $s->price ?>
                        </p>
                        <p class="text-gray-500 text-sm font-semibold tracking-wide">
                            <?= $s->time ?>
                        </p>
                    </td>
                    <td class="px-6 py-4 text-center">
                    <? if($s->change < 0): ?>
                        <span class="text-red-800 bg-red-200 font-semibold px-2 rounded-full">
                            <?= $s->change ?>
                        </span>
                    <? else: ?>
                        <span class="text-green-800 bg-green-200 font-semibold px-2 rounded-full">
                            <?= $s->change ?>
                        </span>
                    <? endif ?>
                    </td>
                    <td class="px-6 py-4 text-center">
                        <? if($s->high == NULL): ?>
                            Market open
                        <? else: ?>
                            <?= $s->high ?>
                        <? endif ?>
                    </td>
                    <td class="px-6 py-4 text-center">
                    <? if($s->low == NULL): ?>
                            Market open
                        <? else: ?>
                            <?= $s->low ?>
                        <? endif ?>
                    </td>
                    <td class="px-6 py-4 text-center">
                        <?= $row["shares"] ?>
                    </td>
                </tr>
                <? endwhile ?>
            </tbody>
        </table>

    </div>
</div>

    </div>

  </body>

</html>
