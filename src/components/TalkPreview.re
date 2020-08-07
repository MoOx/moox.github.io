open ReactNative;
open ReactMultiversal;

let styles =
  Style.(
    StyleSheet.create({
      "text":
        style(
          ~flexDirection=`row,
          ~flex=1.,
          ~alignItems=`flexStart,
          ~lineHeight=28.,
          ~color=Consts.Colors.dark,
          (),
        ),
      "title": style(~fontSize=22., ()),
    })
  );

[@react.component]
let make = (~item: T.partialContentItem, ()) => {
  let href = "/talk/" ++ item##id ++ "/";
  <SpacedView key=item##id horizontal=None>
    <Text style=styles##text>
      <Text> {j|•|j}->React.string </Text>
      <Spacer size=S />
      <UnderlinedTextLink style=styles##title href>
        {item##title->React.string}
        <small>
          {switch (Js.Undefined.toOption(item##conference)) {
           | None => React.null
           | Some(conference) =>
             <Text> {(" @ " ++ conference)->React.string} </Text>
           }}
        </small>
      </UnderlinedTextLink>
      <Spacer size=S />
      {switch (Js.Undefined.toOption(item##lang)) {
       | None => React.null
       | Some(lang) => <Text> {("[" ++ lang ++ "] ")->React.string} </Text>
       }}
    </Text>
  </SpacedView>;
};
