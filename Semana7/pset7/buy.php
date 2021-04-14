<!DOCTYPE html>

<html>

<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link href="https://unpkg.com/tailwindcss@^2/dist/tailwind.min.css" rel="stylesheet">
    <title>CC50 Finanças: Buy</title>
  </head>

  <body>

      <form action="buy2.php" method="post">
      <div class="w-full md:w-1/2 py-10 px-5 md:px-10">
        <div class="flex -mx-3">
          <div class="w-full px-3 mb-5">
            <label for="" class="text-xs font-semibold px-1">Ticket</label>
              <div class="flex">
                <input type="text" name="symbol" class="w-full -ml-10 pl-10 pr-3 py-2 rounded-lg border-2 border-gray-200 outline-none focus:border-indigo-500" placeholder="AAPL">
            </div>
          </div>
        </div>
        <div class="flex -mx-3">
          <div class="w-full px-3 mb-5">
            <label for="" class="text-xs font-semibold px-1">Amount</label>
              <div class="flex">
              <input type="text" name="shares" class="w-full -ml-10 pl-10 pr-3 py-2 rounded-lg border-2 border-gray-200 outline-none focus:border-indigo-500" placeholder="100">
            </div>
          </div>
        </div>
        <div class="flex -mx-3">
          <div class="w-full px-3 mb-5">
            <button type="submit" class="block w-full max-w-xs mx-auto bg-indigo-500 hover:bg-indigo-700 focus:bg-indigo-700 text-white rounded-lg px-3 py-3 font-semibold">BUY</button>
          </div>
        </div>
        </div>
      </form>
  </body>

</html>