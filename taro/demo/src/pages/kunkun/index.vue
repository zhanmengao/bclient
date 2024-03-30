<template>
  <view class="container">
    <button
      v-for="item in btn"
      :size="item.size ? item.size : ''"
      :type="item.type ? item.type : ''"
      :loading="item.loading ? item.loading : false"
      :disabled="item.disabled ? item.disabled : false"
    >
      {{ item.text }}
    </button>
    <button
      class="btn-max-w"
      :plain="true" @click="Taro.redirectTo({
  url: 'pages/index/index',
})" type="primary" >鸡叫按钮</button>
    <button class="btn-max-w" :plain="true" type="primary" :disabled="true">不可点击的按钮</button>
    <button class="btn-max-w" :plain="true">按钮</button>
    <button class="btn-max-w" :plain="true" :disabled="true">按钮</button>
    <button size="mini" type="primary">按钮</button>
    <button size="mini" >按钮</button>
    <button size="mini" type="warn">按钮</button>
    <button open-type="getPhoneNumber" @getphonenumber="callback">按钮</button>
  </view>
</template>

<script>
export default {
  data() {
    return {
      btn: [
        {
          text: '页面主操作 Normal',
          size: 'default',
          type: 'primary'
        },
        {
          text: '页面主操作 Loading',
          size: 'default',
          type: 'primary',
          loading: true,
        },
        {
          text: '页面主操作 Disabled',
          size: 'default',
          type: 'primary',
          disabled: true,
        },
        {
          text: '页面次要操作 Normal',
          size: 'default',
          type: 'default'
        },
        {
          text: '页面次要操作 Disabled',
          size: 'default',
          type: 'default',
          disabled: true,
        },
        {
          text: '警告类操作 Normal',
          size: 'default',
          type: 'warn'
        },
        {
          text: '警告类操作 Disabled',
          size: 'default',
          type: 'warn',
          disabled: true,
        }
      ]
    }
  }
}
</script>
