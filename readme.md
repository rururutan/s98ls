# S98 Loop Serach Support Tool

`s98ls` is a program that supports the detection of loop positions in s98 files.

Compare the data from the specified time to a few seconds from the beginning of the S98 data, and output another S98 file as the loop position when the same location is found.

## Usage

> s98ls [input file] <[output file]> [options]

**options**

        -s?? ... Searching loop start position from ?? sec. needed!
        -l?? ... ?? sec in loop search data from the starting position(default:1sec
        -c?? ... Searching loop point for Specific channel data.
        -o   ... Output log by loop seaching.
                 Output filename is <input file>.log.

## Limitation

Input data is limited to PSG/SSG/OPN/OPNA 1 chip only logs.

## Original author

Manbow-J

## License

	使用､配布条件は特にありません。ただし、日本では著作権は放棄できませんので、
	作者が不利益をこうむるような状況での使用、配布はご遠慮ください。
	再配布も自由ですが、実費以外の金銭の授受がないようにお願いします。
	ソースコードの改変および改変したものをコンパイルした実行ファイルの配布
	は自由に扱ってもらっても構いませんが、必ず、オリジナルのプログラムがわか
	るような形式で再配布してください。

## History

	2011/10/19 Version 0.07
		OPLL support(RuRuRu)
	2011/06/12 Version 0.06
		OPM support (UME-3)
	2011/01/07 Version 0.05
		S98V3 support (RuRuRu)
	2005/04/20 Version 0.04
		チャンネル指定でのループ検索をするオプションを追加( -cxx )
		検索に使用したテーブルをログとして出力するオプションを追加(-o)
	2005/04/20 Version 0.03
		ループの判定を音程(F-Num&SSG Tune)にのみ絞ってみた。
	2005/04/20 Version 0.02
		タイマーの値をデフォルトの場合書き換えていたのでそれを書き換えな
		いように修正。
	2005/04/19 Version 0.01
		オプションスイッチの表示が間違っていたのを修正。
	2005/04/19 Version 0.00
		初版。

