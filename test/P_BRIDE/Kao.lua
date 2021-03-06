World:import("Bride_lib.lua")
Bride:installMainMenuHandler()

decisions = {
    "１日目から始める",
    -- 1st Tale
    "兀突骨大王？",
    "親しみを込めてカッちゃん？",
    "じゃ、葛城クン？",
    -- 3rd Tale
    "①　物のない様子。全てを失った様子。",
    "葛城と一緒に炊飯器のスイッチを入れる係",
    "櫻見さん、逢坂さんとポークのオレンジソースを作る",
    -- 6th Tale
    "宿題は自分の力でやるべき",
    "今度だけ見せてあげたら？",
    -- 7th Tale
    "受ける",
    -- 8th Tale
    "受けない",
    "フライドチキン",
    "菜園をのぞく",
    "とにかく聖ちゃんを脱出させる",
    "⑥　フェラチオ。",
    "葛城と櫻見さんと調味料を買いに",
    "だしの量が微妙に…",
    "葛城と逢坂さんの部屋に行く",
    "葛城の言い分を聞く",
    "葛城の言葉を待つ",
    "先を譲る",
    -- 9th Tale
    "遊園地",
    "葛城と逢坂さんの部屋に行く",
    "畳が気に入らない？",
    -- 10th Tale
    "受ける",
    -- 11th Tale
    "受けない",
    -- 13th Tale
    "受ける",
    "葛城",
    "渡す"
}

World:setDecisionList(decisions)
