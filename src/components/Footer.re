open ReactNative;
open ReactMultiversal;

let styles =
  Style.(
    StyleSheet.create({
      "menu": style(~justifyContent=`center, ~alignItems=`center, ()),
      "bar":
        style(
          ~flexDirection=`row,
          ~flexWrap=`wrap,
          ~justifyContent=`spaceBetween,
          (),
        ),
      "barWrapper": style(~backgroundColor=Consts.Colors.dark, ()),
      "icons": style(~flexDirection=`row, ~alignItems=`center, ()),
      "barLinks": style(~flexDirection=`row, ()),
      "barLink":
        style(
          ~padding=10.->dp,
          ~fontSize=14.,
          ~lineHeight=44.,
          ~color="#FBFCF8",
          (),
        ),
      "barText": style(~fontSize=10., ~lineHeight=20., ~color="#FBFCF8", ()),
      "row":
        style(~flexDirection=`row, ~flexWrap=`wrap, ~alignItems=`center, ()),
      "column": style(~alignItems=`center, ~justifyContent=`center, ()),
    })
  );

[@react.component]
let make = () => {
  <View style=styles##menu>
    <Container style=styles##bar wrapperStyle=styles##barWrapper>
      <View style=styles##barLinks>
        {Consts.menuLinks
         ->Belt.Array.map(item =>
             <TextLink key={item.link} style=styles##barLink href={item.link}>
               item.text->React.string
             </TextLink>
           )
         ->React.array}
      </View>
      <View style=styles##column>
        <View style=styles##row>
          <Text style=styles##barText> "Made with "->React.string </Text>
          <TextLink style=styles##barText href="https://phenomic.io">
            "Phenomic"->React.string
          </TextLink>
          <Text style=styles##barText> " and "->React.string </Text>
          <TextLink style=styles##barText href="https://reasonml.github.io/">
            "Reason"->React.string
          </TextLink>
        </View>
        <TextLink style=styles##barText href="https://github.com/MoOx/moox.io">
          "Source available on GitHub"->React.string
        </TextLink>
      </View>
      <SocialIcons
        wrapperStyle=styles##icons
        iconStyle=styles##barLink
        iconSize=22.
      />
    </Container>
  </View>;
};
