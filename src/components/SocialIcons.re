open BsReactNative;

let component = ReasonReact.statelessComponent("SocialIcons");

[@react.component]
let make =
    (
      ~wrapperStyle,
      ~iconStyle,
      ~iconColor=Consts.Colors.lightest,
      ~iconSize=16.,
      /* note the default value that just wrap with a simple node */
      ~iconWrapperFunc=(~children) => <Text> ...children </Text>,
      (),
    ) =>
  ReactCompat.useRecordApi({
    ...component,
    render: _self =>
      <View style=wrapperStyle>
        {Consts.socialLinks
         ->Belt.Array.map(item =>
             <ViewLink
               key={item.link}
               style=iconStyle
               href={item.link}
               accessibilityLabel={item.text}>
               {iconWrapperFunc(
                  ~children=item.componentFunc(~iconColor, ~iconSize),
                )}
             </ViewLink>
           )
         ->ReasonReact.array}
      </View>,
  });
